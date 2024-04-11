#ifndef TREEELEM_H
#define TREEELEM_H

#include <string>
#include <map>

using namespace std;

struct TreeElem;
using ElPtr = TreeElem*;

/**
 * elem[s] refers to the element with string identifier s
 */
static map<string,ElPtr> elem;

struct TreeElem {

	string id;
    ElPtr parent;
    int rank;

	ElPtr link; //circular linked list for print

	TreeElem(string s) : id(s), parent(this), rank(0), link(this) {
        elem[s] = this;
    }

	string toString() { return id; }

	static ElPtr MakeSet(string s) {
        if (elem.find(s) != elem.end()) {
            return nullptr;
        }
        return new TreeElem(s);
    }

	static ElPtr FindSet(ElPtr x) {
        if (x != x->parent) {
            x->parent = FindSet(x->parent);
        }
        return x->parent;
    }

	static void Union(ElPtr x, ElPtr y) {
        Link(FindSet(x), FindSet(y));
    }

	static void Link(ElPtr x, ElPtr y) {

        // circular linked list portion, switch the backwards pointers
        ElPtr temp = x->link;
        x->link=y->link;
        y->link=temp;

        if (x->rank > y->rank) {
            y->parent = x;
        } else {
            x->parent = y;
            if (x->rank == y->rank) {
                y->rank++;
            }
        }
	}
};

#endif // TREEELEM_H
