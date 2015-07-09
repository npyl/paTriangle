//
//  PaTriangleSolution.hpp
//  PaTriangle
//
//  Created by Nickolas Pylarinos on 5/22/15.
//  Copyright (c) 2015 npylFoundation. All rights reserved.
//

#ifndef PATRIANGLE_SOLUTION_HPP
    #define PATRIANGLE_SOLUTION_HPP

typedef unsigned uINT;
typedef unsigned long uLNG;

class PaTriangleSolution
{
    private:
        static uINT            nRows;

        uLNG            p;
        uINT            c;

        uLNG            **sequences;
        
    private:
    #ifdef FAST_MODE
        inline uLNG     m(const uINT r, const uLNG p, const uINT c);
        inline void     S(const uINT i);
    #else
        uLNG            m(uINT const r, const uLNG p, const uINT c);
        void            S(const uINT i);
    #endif
        
    public:
        PaTriangleSolution(const uINT nRows, uLNG **sequences);
        ~PaTriangleSolution(void);
        
        void            formSequences(void);
        void            printSequences(void);
};

#endif