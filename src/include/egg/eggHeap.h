// eggHeap.h
//
// Copyright (c) 2021 TheLordScruffy
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <common.h>
#include <egg/eggDisposer.h>
#include <rvl/types.h>

namespace EGG
{

    class Heap : public Disposer
    {
    public:
        virtual ~Heap();
        /* Not included */
        virtual s32 _0(); // getHeapKind
        virtual s32 _1(); // initAllocator
        virtual void *alloc(u32 len, s32 align) = 0;
        virtual void free(void *block) = 0;
        /* Not included */
        virtual s32 _2(); // destroy
        virtual s32 _3(); // resizeForMBlock
        virtual s32 _4(); // getAllocatableSize
        virtual s32 _5(); // adjust

        /* Data not included */
    };

} // namespace EGG

typedef struct
{
    u8 _00[0x38 - 0x00];
} EGG_Heap;
static_assert(sizeof(EGG_Heap) == 0x38);

void *EGG_Heap_alloc(u32 size, s32 align, EGG_Heap *heap);

void EGG_Heap_free(void *memBlock, EGG_Heap *heap);

void *spAlloc(size_t size, size_t align, EGG_Heap *heap);

void *spAllocArray(size_t count, size_t size, size_t align, EGG_Heap *heap);

void spFree(void *memBlock);