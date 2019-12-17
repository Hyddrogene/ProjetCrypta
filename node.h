#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;

typedef size_t u32;

template<class T>
class Node {
public:
	typedef string to_string_fn(T& data);
	
	T m_data;
	Node<T> *m_parent;
	vector<Node<T> *> m_nodes;
	
	
	void print(ostream& out, vector<Node<T> *>& v, to_string_fn& f) {
		for (u32 i = 0; i < v.size()-1; ++i) out << "  ";
		out << "|-" << f(m_data) << endl;
		v.push_back(this);
		for (auto n : m_nodes) {
			n->print(out, v, f);
		}
		v.pop_back();
	}
	
public:	
	Node(T data) {
		m_data = data;
		m_parent = nullptr;
	}
	
	virtual ~Node() {

	}
	
	void free() {
		for (auto n : m_nodes) {
			n->free();
			delete n;
		}
	}
	
	T& data() {
		return m_data;
	}
	
	Node<T> *parent() {
		return m_parent;
	}
	
	void parent(Node<T> *parent) {
		m_parent = parent;
	}
	
	void add(Node<T> *node) {
		m_nodes.push_back(node);
		node->m_parent = this;
	}
	
	u32 nbr_offspring() {
		return m_nodes.size();
	}
	
	Node<T> *offspring(u32 n) {
		assert((0 < n) && (n < m_nodes.size()));
		return m_nodes[n];
	}

		
	bool is_leaf() {
		return m_nodes.size() == 0;
	}

	void to_text(ostream& out, to_string_fn& f) {
		vector<Node<T> *> v;
		out << f(m_data) << endl;
		v.push_back(this);
		for (auto n : m_nodes) {
			n->print(out, v, f);
		}
		v.pop_back();
		
	}
	
	ostream& print(ostream& out) {
		out << m_data;
		if (m_nodes.size() > 0) {
			out << "(";
			for (u32 i = 0; i < m_nodes.size(); ++i) {
				m_nodes[i]->print(out);
				if (i < (m_nodes.size()-1)) out << ",";
			}
			out << ")";
		}
		return out;
	}
	
	friend ostream& operator<<(ostream& out, Node<T>& n) {
		return n.print(out);
	}	
};

#endif

