/* 26.01.16 - Xavier Ruppen - HPC - REDS - HEIG-VD */

#include <stdio.h>
#include <stdlib.h>
#include "benchmark/benchmark.h"
#include "bench.h"

extern "C" {
#include "include/array_util.h"
#include "include/list_util.h"
}

class MatrixFixture : public benchmark::Fixture {
public :
    void SetUp(const ::benchmark::State&)
    {
        array = array_init(SIZE);
        list = list_init(SIZE);
    }

    void TearDown(const ::benchmark::State&)
    {
        list_clear(list);
        array_clear(array);
    }

protected :
    uint64_t * array;
    struct list_element * list;
};


BENCHMARK_F(MatrixFixture, matrix_mult)(benchmark::State& state) {
    while (state.KeepRunning()) {
        
        array_sort(array, SIZE);
        array_clear(array);
        array = array_init(SIZE);
    }
}

BENCHMARK_F(MatrixFixture, matrix_mult_xchg)(benchmark::State& state) {
    while (state.KeepRunning()) {
           
        list_sort(list);
        list_clear(list);
        list = list_init(SIZE);
    }
}

BENCHMARK_MAIN();
