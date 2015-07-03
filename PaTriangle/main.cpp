//
//  main.cpp
//  PaTriangle
//
//  Created by npyl on 8/4/15.
//  Copyright (c) 2015 npylFoundation. All rights reserved.
//

#define FAST_MODE
#define DEBUG_MODE

#include "PaTriangleSolution.h"

#include <iostream>
using namespace std;

int main(void) {
    uINT nRows = 0;             // At least one row
    uLNG **sequences = NULL;
    
    cout << "PaTriangle v0.5.17 | by npyl\n==================\n\n"
    << "Please type number of rows to generate:" << endl;
    cin  >> nRows;
    
    if( nRows >= 1 )
    {
        /*      Initialisations     */
        try{
            sequences = new uLNG*[nRows];
            for( uINT a = 0; a < nRows; a++ )
                sequences[a] = new uLNG[(a + 1)];
            
            /*      Solution        */
            PaTriangleSolution *paTriangle = new PaTriangleSolution(nRows, sequences);
            paTriangle -> formSequences();
            paTriangle -> printSequences();
            
            cout << sequences[0][0] << endl;
            
            if( nRows >= 2 )
                cout << sequences[1][0] << " " << sequences[1][1] << endl;
            
            for( uINT a = 2; a < nRows; a++ )
            {
                for( uINT b = 0; b <= (a+1); b++)
                    cout << sequences[a][b] << " ";
                
                cout << endl;
            }
            
            /*      House - Keeping     */
            delete paTriangle;
            paTriangle = 0;
            
            for( uINT a = 0; a < nRows; a++ )
                delete sequences[a];
            delete[] sequences;
        }
        catch(exception e)
        {
            cout << "Caught exception: " << endl
            << e.what() << endl;
        }
    }
    else
        cerr << "Please type a number >= 1 next time!" << endl;
    
    return 0;
}

/*
 for( uINT a = 0; a < (nRows - 1); a++ ) {
 for( uINT b = 0; b <= a; b++ )
 std::cout << sequences[a][b] << " ";
 
 std::cout << std::endl;
 }*/

/*
 cout << sequences[0][0] << endl;
 
 if( nRows >= 2 )
 cout << sequences[1][0] << " " << sequences[1][1] << endl;
 
 for( uINT a = 2; a < nRows; a++ )
 {
 for( uINT b = 0; b <= (a+1); b++)
 cout << sequences[a][b] << " ";
 
 cout << endl;
 }*/