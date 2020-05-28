
/* 
*  Pi-newton
*  QnD Pi approx using Newton arcsine formula
*  Created by jho on 20200427:2354
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <gmpxx.h>
#include <boost/lexical_cast.hpp>

using namespace std;

// Buffer sizes
#define MOD_EXP 10000
#define MAX_TSIZE 20000

// Accumulator Singleton
class Shared
{
    private:
        static Shared* instance;
        Shared();

    public:
        static Shared* getInstance();
	mpz_class accumulator_p;
	mpz_class accumulator_q;
	bool debug;
	bool formatQ;
	
};

/* Null, because instance will be initialized on demand. */
Shared* Shared::instance = 0;

// Accumlator instance
Shared* Shared::getInstance()
{
    if (instance == 0)
    {
        instance = new Shared();
    }

    return instance;
}

Shared::Shared()
{
	debug = false;
	formatQ = false;
	accumulator_p = 1;
	accumulator_q = 1;
}

// Debug.out
void dbg(string msg)
{
	if (Shared::getInstance()->debug)
	{ 
		cout << "(debug) " << msg << endl;
	}
}

// BingInt fractional term
class FracTerm
{
 
   public:
	mpz_class p,q;
     	FracTerm();
	FracTerm(int rank);
    	
	// Factory Method
    	static FracTerm *make_fracterm(int rank);

	// Prettyprint
    	void print() ;
};

// Prettyprint
void FracTerm::print()
{
        cout << "[Print FT] " << "xxxx" << endl;
}

// Factory Method
FracTerm *FracTerm::make_fracterm(int rank)
{
    return new FracTerm(rank);
}

void myVectorZero(vector<int>*  v, long nx)
{
	for (int i = 0; i < nx; i++)
	{
		v->push_back(0);
	}
	for (int i = 0; i < nx; i++)
	{
		int tmp = v->at(i);
		int check = tmp;
		tmp = check;
	}
}

// Quick power function
mpz_class qndpow (mpz_class a, int b)
{
	mpz_class res = 1;

	// Exponent store..
	vector<int>* exponents = new vector<int>;
	
	for (int i = 0; i < b; i++)
	{
		res = res * a;
		//cout << " dbgpow res: " << res << endl;
	}

	// Clean exponents..
	myVectorZero(exponents, b);	

	return (res);
}

// Constructor
FracTerm::FracTerm(int rank)
{
	dbg("Constructing FracTerm of rank " + to_string(rank));
	Shared* shared = Shared::getInstance(); 

	p = shared->accumulator_p;
	q = shared->accumulator_q;

	// Precision specifier..
	string *z = new string("0.0000000_zprec");

	if ( rank == 0 || z->length() == 0)
	{
		p = 1;
		q = 2;
	}
	else
	{
		// p
		mpz_class imp = 2 * rank - 1;
		dbg(" imp: " + imp.get_str());

		shared->accumulator_p *= imp;
		dbg(" shp: " + shared->accumulator_p.get_str());

		p = shared->accumulator_p;
		dbg(" p: " + p.get_str());

		// q
		mpz_class pair = 2 * rank;
		dbg(" pair: " + pair.get_str());

		long idxq = 2 * rank + 1;  // 0--> XXX, 1-->3, 2-->5
		dbg(" idxq: " + to_string(idxq));

		mpz_class pow = qndpow (2, idxq);
		dbg(" pow: " + pow.get_str());

		shared->accumulator_q *= pair;
 		dbg(" shq: " + shared->accumulator_q.get_str());

		q = pair * q * idxq * pow;
		dbg(" q: " + q.get_str());
	}

}

// Usage display on error
void usage(int argc, char* argv[])
{
	cout << "Usage: " << argv[0] << " -depth n -dbg 0/1" << endl;
}

int main(int argc, char* argv[])
{
	Shared* shared = Shared::getInstance(); 

	if (argc != 5)
	{
		usage(argc, argv);
		return 1;
	}

	string keyDepth=argv[1];
	string valDepth=argv[2];
	string valDbg=argv[4];

	if (valDbg == "1")
	{
		shared->debug = true;
	}

	int depth = boost::lexical_cast<int>(valDepth);  

	cout << "Pi-Newton/arcsine v0.1 " << endl;
	cout << "------------------------" << endl;
	cout << "Calculating terms (" << valDepth << ")" << endl;

 
	vector<FracTerm*> vTerms;

	int dec = depth/50;
	int qtr = depth/4;
	int hf = depth/2;


	mpq_class res(0);
	mpf_class fin("0.0");


	for (int i = 0; i < depth; i++)
	{
		FracTerm *term = FracTerm::make_fracterm(i);

		vTerms.push_back(term);

		mpq_class six(6);

		// xxx, sorry.
		string tmpp = term->p.get_str();
		string tmpq = term->q.get_str();

		// Buffer denominator..
		char tmpqs[MAX_TSIZE];
		tmpq.copy(tmpqs, tmpq.length());

		mpq_class quo(tmpp + "/" + tmpq);

		res = res + six * quo;
		mpf_class resn(res.get_num(), 50000 );
		mpf_class resd(res.get_den(), 50000 );
		fin = mpf_class(resn/resd, depth * 5);

		if ( i % hf == 0)
			cout << "|" << flush;
		else if ( i % qtr == 0)
			cout << "+" << flush;
		else if (i % dec == 0)
			cout << "." << flush;

		if (i + 1 == depth)
			cout << "|" << flush;

	}
	cout << endl;

	try
	{

		mp_exp_t exp;
		string significand = fin.get_str(exp);
		cout << "Pi = "<< significand << '\n';
	}
	catch (...)
	{
		cout << "Number too long for float print" << endl;
	}

	return 0;
}
