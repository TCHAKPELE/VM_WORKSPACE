#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

int main()
{
    FILE *f = NULL;
    char value='x';
    int x = 1;
    int nbrchar =0;
    char test [100]={0};
    char dic [1000000]={0};
    int i =0;
    int j,increment;
    int a =0;
    int occurrence=0;
    char test2[100]={0};
    int tst = 0;
    int code=0;
    f=fopen("words.txt","r");
if(f==NULL){

cout << "Impossible d'ouvrir le fichier " << endl;

code = 3;

return code;

}
else
{
    cout << "Entrez la chaine de caractere  " ;

cin >> test;


    while(test[i]!=0){
test2[i]=test[i];
i++;
    }

    cout << " la chaine saisie est : " << endl;

    for(j=0;j<i;j++){

       cout << test[j] << endl;

    }

    if(f==NULL){
      cout << "Erreur ouverture fichier" << endl;

    }
    else{
cout << " les anagrammes sont : " << endl;

        while(value!=EOF){

        value = fgetc(f);

          dic[a]=value;
          if(value == '\n'){


            if(nbrchar == i){

                for(increment = 0 ;increment <i;increment++){

                     test2[increment]=test[increment];

                }

                   for(increment = 0 ;increment <i;increment++){

                     for(j = a-nbrchar ;j <=a;j++){

                    if(test2[increment]==dic[j]){

                        occurrence++;
			test2[increment]='#';


                    }

                }

                }




                if(i==occurrence){

                        cout << " ligne " <<x<<" : " << endl;

                    for(j = a-nbrchar ;j <=a;j++){

                    cout << dic[j] << endl;

                    tst ++;

                }


            }



          }
         
          occurrence = 0;
           x++;
           nbrchar = 0;
          }
          else{

          nbrchar++;

          }
          a++;


        }

                        if(tst==0){

                    cout << "aucun resultat" << endl;

                    code = 1;

                    return code;
                }



    }


}
return code;
}
