/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：ptr_operator.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年10月29日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>

class obj{
	private:
		static int i,j;
	public:
		void f() const{cout << i++ << endl;}
		void g() const{cout << j++ << endl;}
};

int obj::i = 10;
int obj::j = 12;

class obj_container{
	private:
		vector<obj*> a;
	public:
		void add(obj* obj){a.push_back(obj);}
		friend class smart_pointer;
};

class smart_pointer{
private:
	obj_container oc;
	int index;
public:
	smart_pointer(obj_container& objc)
	{
		oc = objc;
		index = 0;
	}

	bool operator++()
	{
		if(index >= oc.a.size()) return false;
		if(oc.a[++index] == 0) return false;
		return true;
	}

	bool operator ++(int)
	{
		return operator++();
	}

	obj* operator ->() const
	{
		if(!oc.a[index]){
			cout << "zero value\n";
			return (obj*)0;
		}
		return oc.a[index];
	}
};


int main()
{
	const int sz = 10;
	obj o[sz];
	obj_container oc;
	for(int i=0;i<sz;i++)
		oc.add(&o[i]);
	smart_pointer sp(oc);
	do{
		sp->f();
		sp->g();
	}while(sp++);
	return 0;
}
