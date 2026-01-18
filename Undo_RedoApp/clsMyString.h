#pragma once
#include <iostream>
#include <stack>
using namespace std;
class clsMyString {
	string _Value = "";
	stack<string>_Undo;
	stack<string>_Redo;
public:
	void SetValue(string Value) {
		_Value = Value;
		_Undo.push(_Value);
	};
	string GetValue() {
		return _Value;
	};
	__declspec(property(get = GetValue, put = SetValue))string Value;
	void Undo() {
		if (!_Undo.empty()) {
			_Redo.push(Value);
			_Undo.pop();
			if (!_Undo.empty())
				_Value = _Undo.top();
			else
				_Value = "";
		};
	};
	void Redo() {
		if (!_Redo.empty()) {
			_Value = _Redo.top();
			_Undo.push(_Value);
			_Redo.pop();
		};
	};
};