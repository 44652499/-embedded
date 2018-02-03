#include <iostream>
using namespace std;
class Context;
class State
{
  public:
      virtual void Handle(Context* pContext)=0;
};
class Context
{
  public:
     Context(State* pState)
     {
     	 this->_state = pState;
     }
     void Request()
     {
     	if(NULL!= this->_state)
        {
         	this->_state->Handle(this);
     	}
     }
     void ChangeState(State* pState)
     {
     	this->_state = pState;
     }
 private:
     State* _state;
};

class EndState : public State
{
 public:
     virtual void Handle(Context* pContext)
     {
     	cout << "EndState" << endl;
     }
}; 
class ConcreteStateC : public State
{
 public:
     virtual void Handle(Context* pContext)
     {
     	cout << "ConcreteStateC" << endl;
        pContext->ChangeState(new EndState());
     }
}; 
class ConcreteStateB : public State
{
	public:
     virtual void Handle(Context* pContext)
     {
     	cout << "ConcreteStateB" << endl;
        pContext->ChangeState(new ConcreteStateC());
     }
}; 

class ConcreteStateA : public State
{
 public:
     virtual void Handle(Context* pContext)
     {
     	 cout << "ConcreteStateA" << endl;
	     pContext->ChangeState(new ConcreteStateB());
     }
};
int main(int argc, char const *argv[])
{
	 State* pState = new ConcreteStateA();
     Context* pContext = new Context(pState);
     int i;
     for(i=0;i<5;i++)
     {
     	pContext->Request();
     	pContext->Request();
     	pContext->Request();
     	pContext->Request();
     	pContext->ChangeState(pState);
     	cout<<endl<<endl;
     }     
	 return 0;
}