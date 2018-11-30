#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
	private:
		static unsigned int GLOBAL_ID;
		unsigned int privateID;
		int id;
		T data;
	public:
		Node(){this->id=-1; this->data=T(); this->privateID=this->GLOBAL_ID++;};
		Node(int id, T data){this->id=id; this->data=data; this->privateID=this->GLOBAL_ID++;};
		Node(T data){this->data=data; this->privateID=this->GLOBAL_ID++; this->id=this->privateID;};
		int getID(){return this->id;};
		void setID(int num){this->id=num;};
		int getData(){return this->data;};
		void setData(T val){this->data = val;};
		bool operator ==(Node<T> other){return other.privateID == this->privateID;};
};

template <class T>
unsigned int Node<T>::GLOBAL_ID = 0;

#endif
