// Observers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <memory>
#include "../Common2.h"
using namespace std;


class EvenNumberObservable : IObservable<int>
{
	int  *_numbers;
	int _count;
public:
	EvenNumberObservable(int numbers[],int count):_numbers(numbers),_count(count){}
	bool Subscribe(IObserver<int>& observer){
		 for (int i = 0; i < _count; ++i)
			 if (_numbers[i] % 2 == 0)
				observer.OnNext(_numbers[i]);
		observer.OnCompleted();
		return true;
	}
};


class SimpleObserver :  public IObserver<int>
{
public:
	 void OnNext(int value) { cout << value << endl; }
	 void OnCompleted() { cout << _T("hello completed") << endl; }
	 void OnError( CustomException * ex) {}
};


int main()
{
	int x[] = { 1,2,3,4,5 };

	EvenNumberObservable * t = new EvenNumberObservable(x, 5);
	IObserver<int> *xy = new SimpleObserver();
	
	t->Subscribe(*xy);

	delete xy;
	delete t;

    return 0;
}

