//
//  PaTriangleSolution.cpp
//  PaTriangle
//
//  Created by Nickolas Pylarinos on 5/22/15.
//  Copyright (c) 2015 npylFoundation. All rights reserved.
//

#include "PaTriangleSolution.hpp"

#include <iostream>

PaTriangleSolution::PaTriangleSolution(const uINT imported_nRows, uLNG **imported_sequences)
{
    nRows       = imported_nRows;
    sequences   = imported_sequences;
    
    p       = 0;
    c       = 0;
}

PaTriangleSolution::~PaTriangleSolution(void)
{
}

uLNG                    PaTriangleSolution::m(const uINT r, const uLNG p, const uINT c)
{
    return p * ( r - c ) / ( c + 1 );
}

void                    PaTriangleSolution::S(const uINT i)
{
    const uINT lei = (i + 1);
    uINT e = 0;
    
    p = 1;
    c = 0;
    
    sequences[i][0] = 1;
    
    do {
        ++e;
        
        p = m(i, p, c);
        sequences[i][e] = p;
        ++c;
        
    } while( e < lei )
        ;
}

void                    PaTriangleSolution::formSequences(void)
{
    for(uINT i = 0; i < nRows; i++)
        S(i);
    
    return;
}

void                    PaTriangleSolution::printSequences(void)
{
    uINT        lli = 0;        // lli stands for last line index
    
    for( uINT a = 0; a < nRows; a++ ) {
        lli = (a + 1);
        
        for( uINT b = 0; b < lli; b++ )
            std::cout << sequences[a][b] << " ";
        
        std::cout << std::endl;
    }
    
    return;
}