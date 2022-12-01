#include "Image.h"
#include <fstream>
using namespace std;


bool Image::imread(const char* filename)
{
    ifstream lecture(filename);
    char fileType[2] = {'P', '2'};
    char fileTypeRead[2];
    double nrows, ncols;
    bool out = true;
    if (!lecture.fail())
    {
        lecture >> fileTypeRead;
        cout << "fileTypeRead: " << fileTypeRead <<endl;;

        for (int i(0); i<2; i++)
        {
            if (fileType[i] == fileTypeRead[i])
                {out = out & true;}
            else
                {out = out & false;}

        }
        if (not out)
        {
            cout << "la lecture a echoue" << endl;
            return out;
        }
        
        else
        {
            lecture >> nrows;
            lecture >> ncols;

            for (int i(0); i<nrows; i++) // Variation suivant les lignes
            {
                for (int j(0); j<ncols; j++) // Variation suivant les colonnes
                
                    lecture >> v[i][j];
            }
            return out;
        }
           
        

    }lecture.close();
    
}