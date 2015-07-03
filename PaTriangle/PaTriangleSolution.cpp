//
//  PaTriangleSolution.cpp
//  PaTriangle
//
//  Created by Nickolas Pylarinos on 5/22/15.
//  Copyright (c) 2015 npylFoundation. All rights reserved.
//

#include "PaTriangleSolution.hpp"

#include <iostream>

PaTriangleSolution::PaTriangleSolution(uINT imported_nRows, uLNG **imported_sequences)
{
    nRows       = imported_nRows;
    sequences   = imported_sequences;
    
    p       = 0;
    c       = 0;
}

PaTriangleSolution::~PaTriangleSolution(void)
{
}

uLNG                    PaTriangleSolution::m(uINT r, uLNG p, uINT c)
{
    return p * ( r - c ) / ( c + 1 );
}

void                    PaTriangleSolution::S(unsigned r)
{
#ifdef DEBUG_MODE
    uINT pos = 0;
#endif
    
    p = 1;
    c = 0;
    uLNG result = 0;
    
    sequences[(r - 1)][0] = 1;
    
    for( uINT elC = 1; elC <= r; elC++ )
    {
        result = m(r, p, c);
        
#ifdef DEBUG_MODE
        pos = (r - 1);
#endif
        
        sequences[(r - 1)][elC] = result;
        
        p = result;
        c++;
    }
}

void                    PaTriangleSolution::formSequences(void)
{
    sequences[0][0] = 1;
    
    if( nRows == 2 )
    {
        sequences[1][0] = 1;
        sequences[1][1] = 1;
    }
    else if( nRows > 2 )
    {
        sequences[1][0] = 1;
        sequences[1][1] = 1;
        
        for( uINT currentRow = 3; currentRow <= nRows; currentRow++ )
            S(currentRow);
    }
    
    return;
}

void                    PaTriangleSolution::printSequences(void)
{
    const uINT ali = (nRows - 1);
    
    for( uINT a = 0; a < ali; a++ ) {
        for( uINT b = 0; b < a; b++ )
            std::cout << sequences[a][b] << " ";
        
        std::cout << std::endl;
    }
    
    return;
}