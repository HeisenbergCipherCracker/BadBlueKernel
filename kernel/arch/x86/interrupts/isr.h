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

 */
#ifndef _ISR_H_
#define _ISR_H_

/**
 * @file isr.h
 * @author Konstantin Tcholokachvili
 * @date 2013
 * @license MIT License
 *
 * Exceptions handling
 */

#include <arch/x86/registers.h>

/** Setup interruption service request handling */
void x86_isr_setup(void);

/** Interruption service request handler */
void x86_isr_handler(struct regs *r);

#endif // _ISR_H_
