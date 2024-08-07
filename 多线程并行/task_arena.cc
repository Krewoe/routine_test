#include <iostream>
#include <tbb/parallel_for.h>
#include <tbb/task_arena.h>
#include <vector>
#include <cmath>


// arena 竞技场,可以指定线程数量执行循环
int main() {

    size_t n = 1 << 26;
    std::vector<float> a(n);

    // 指定4个线程执行
    tbb::task_arena ta(4);
    ta.execute([&] {
        tbb::parallel_for((size_t)0, (size_t)n, [&](size_t i) {
            a[i] = std::sin(i);
        });
    });

    return 0;
}