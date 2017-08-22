#include"Alloc1.h"

//通过trace_debug做白盒测试
//trace--》跟踪观察调用了哪些接口
void TestAlloc1()
{
	void* p1 = DefaultAllocTemplate<false, 0>::Allocate(200);
	DefaultAllocTemplate<false, 0>::DeAllocate(p1, 200);

	void* p2 = DefaultAllocTemplate<false, 0>::Allocate(15);
	DefaultAllocTemplate<false, 0>::DeAllocate(p2, 15);

}

//1.直接打印到控制台
//2.输出到文件中
//测试系统堆内存耗尽的场景
void TestAlloc2()
{
	cout << "测试系统堆内存耗尽" << endl;

	DefaultAllocTemplate<false, 0>::Allocate(1024 * 1024 * 1024);
	DefaultAllocTemplate<false, 0>::Allocate(1024 * 1024 * 512);
	DefaultAllocTemplate<false, 0>::Allocate(1024 * 1024);

	//不好测试，说明系统管理小块内存的能力还是很强的。
	for (int i = 0; i< 100000; ++i)
	{
		void* p1 = DefaultAllocTemplate<false, 0>::Allocate(128);
	}
}


int main()
{
	TestAlloc1();
	//TestAlloc2();
	return 0;
}
