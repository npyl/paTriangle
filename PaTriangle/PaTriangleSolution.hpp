//
//  PaTriangleSolution.h
//  PaTriangle
//
//  Created by Nickolas Pylarinos on 5/22/15.
//  Copyright (c) 2015 npylFoundation. All rights reserved.
//

#ifndef __PaTriangle__PaTriangleSolution__
    #define __PaTriangle__PaTriangleSolution__

typedef unsigned uINT;
typedef unsigned long uLNG;

class PaTriangleSolution
{
    private:
        uINT            nRows;
    
        uLNG            p;
        uINT            c;
    
        uLNG            **sequences;
        
    private:
    #ifdef FAST_MODE
        inline uLNG     m(uINT r, uLNG p, uINT c);
        inline void     S(uINT r);
    #else
        uLNG            m(uINT r, uLNG p, uINT c);
        void            S(uINT r);
    #endif
        
    public:
        PaTriangleSolution(uINT nRows, uLNG **sequences);
        ~PaTriangleSolution(void);
        
        void            formSequences(void);
        void            printSequences(void);
};

#endif /* defined(__PaTriangle__PaTriangleSolution__) */
