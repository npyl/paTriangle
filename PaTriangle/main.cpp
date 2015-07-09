//
//  main.cpp
//  PaTriangle
//
//  Created by npyl on 8/4/15.
//  Copyright (c) 2015 npylFoundation. All rights reserved.
//

#define FAST_MODE

#include "PaTriangleSolution.hpp"

#include <iostream>
using namespace std;

/*			Functions			*/
void		beforeMain(void) __attribute__ ((constructor));	// called before main
void		afterMain(void) __attribute__ ((destructor));	// called after main


/*			Functions			*/
void		beforeMain(void) {
    cout << "PaTriangle v0.5.2 | by npyl\n=============================\n\n"
    << "Please type number of rows to generate:" << endl;
}

int main(void) {
    uINT nRows = 0;             // At least one row
    uLNG **sequences = NULL;
    
    cin  >> nRows;
    
    if( nRows >= 1 )
    {
        /*      Initialisations     */
        try{
            sequences = new uLNG*[nRows];
            for( uINT a = 0; a < nRows; a++ )
                sequences[a] = new uLNG[(a + 1)];
            
            /*      Solution        */
            PaTriangleSolution *paTriangle = new PaTriangleSolution( nRows, sequences);
            paTriangle -> formSequences();
            
            /*      House - Keeping     */
            delete paTriangle;
            paTriangle = 0;
            
            for( uINT a = 0; a < nRows; a++ )
                delete sequences[a];
            delete[] sequences;
        }
        catch(exception e)
        {
            cerr << "Caught exception: " << endl
            << e.what() << endl;
        }
    }
    else
        cerr << "Please type a number >= 1 next time!" << endl;
    
    return 0;
}