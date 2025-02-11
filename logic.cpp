#include <iostream>
#include <vector>

using namespace std;


////////////////////
// Logic State
////////////////////
class State{
	bool state;
public:
	State(bool state) : state(state) {}
	bool get() { return state; }
};


////////////////////
// Logic Gates
////////////////////
class Gate{
public:
	static State AND(vector<State> states);
	static State OR(vector<State> states);
	static State NOT(State state);
	static State NAND(vector<State> states);
	static State NOR(vector<State> states);
	static State XOR(vector<State> states);
	static State XNOR(vector<State> states);
};


int main()
{
	vector<State> states = {State(1), State(0), State(1)};
	
	cout << "Inputs:\t"; for(int i=0;i<3;i++) cout << states.at(i).get() << ' '; cout << endl;
	cout << "AND:\t" << Gate::AND(states).get() << endl;
	cout << "OR:\t" << Gate::OR(states).get() << endl;
	cout << "NOT:\t1->" << Gate::NOT(State(1)).get() << endl;
	cout << "NAND:\t" << Gate::NAND(states).get() << endl;
	cout << "NOR:\t" << Gate::NOR(states).get() << endl;
	cout << "XOR:\t" << Gate::XOR(states).get() << endl;
	cout << "XNOR:\t" << Gate::XNOR(states).get() << endl;
}

State Gate::AND(vector<State> states)
{
	for(unsigned int i=0;i<states.size();i++)
		if (!states.at(i).get())
			return State(0);
	return State(1);
}

State Gate::OR(vector<State> states)
{
	for(unsigned int i=0;i<states.size();i++)
		if (states.at(i).get())
			return State(1);
	return State(0);
}

State Gate::NOT(State state)
{
	return State(!state.get());
}

State Gate::NAND(vector<State> states)
{
	return Gate::NOT(Gate::AND(states));
}

State Gate::NOR(vector<State> states)
{
	return Gate::NOT(Gate::OR(states));
}

State Gate::XOR(vector<State> states)
{
	int count = 0;
	for(unsigned int i=0;i<states.size();i++)
		if (states.at(i).get())
			count++;
	
	return State(count % 2);
}

State Gate::XNOR(vector<State> states)
{
	return Gate::NOT(Gate::XOR(states));
}

