/*
    Copyright (c) 2014 Martin Sustrik  All rights reserved.
    Copyright 2016 Garrett D'Amore

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom
    the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "task.h"
#include "../../utils/attr.h"
#include "../../utils/err.h"

void nn_task_init (struct nn_task *self, uint32_t id, int src,
    struct nn_fsm *owner)
{
    self->id = id;
    self->sent_to = NULL;
    nn_msg_init (&self->request, 0);
    nn_msg_init (&self->reply, 0);
    nn_timer_init (&self->timer, src, owner);
}

void nn_task_term (struct nn_task *self)
{
    nn_timer_term (&self->timer);
    nn_msg_term (&self->reply);
    nn_msg_term (&self->request);
}
