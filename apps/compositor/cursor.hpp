/**
 * MIT License
 *
 * Copyright (c) 2024 Heisenberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * @author Heisenberg
 * @file cursor.hpp

 */
#ifndef _CURSOR_H
#define _CURSOR_H

#include <types.hpp>

#define ALPHA 0
#define BLACK 1
#define WHITE 2

#define CURSOR_W 12
#define CURSOR_H 19

LIBHeisenKernel::uint8_t cursorBitmap[CURSOR_W * CURSOR_H] = 
{
    BLACK,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,ALPHA,
    BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,
    BLACK,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,BLACK,BLACK,BLACK,BLACK,BLACK,
    BLACK,WHITE,WHITE,WHITE,BLACK,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,WHITE,BLACK,ALPHA,BLACK,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,
    BLACK,WHITE,BLACK,ALPHA,ALPHA,BLACK,WHITE,WHITE,BLACK,ALPHA,ALPHA,ALPHA,
    BLACK,BLACK,ALPHA,ALPHA,ALPHA,ALPHA,BLACK,WHITE,WHITE,BLACK,ALPHA,ALPHA,
    ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,BLACK,WHITE,WHITE,BLACK,ALPHA,ALPHA,
    ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,ALPHA,BLACK,BLACK,ALPHA,ALPHA,ALPHA
};

#endif