/*===============================================================
 *   Copyright (C) 2019 All rights reserved.
 *   
 *   文件名称：base_ptr.cpp
 *   创 建 者：pengtangtang
 *   创建日期：2019年10月27日
 *   描    述：
 *
 *   更新日志：
 *
 ================================================================*/
using namespace std;
#include <iostream>
#include <cstring>
class A { 
	public: 
	       	A(){}
	         	 ~A( ) { } 
		         	 virtual void output( ) { } 
};
class B:public A { 
	public:      
		B(const char* info){       
			m_buf=new char[256];       
			strcpy(m_buf,info);  
		}    
		~B( ) { 
			delete[] m_buf;
		}      
		virtual void output( ) { 
			cout<<m_buf; 
		}
	private:    
		char * m_buf; 
};
void main() { 
	   	A*pa = new B("FLAME!") ;   
		pa->output( );   
		delete pa;  
} 
