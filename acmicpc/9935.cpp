#include <iostream>
#include <string>
#include <vector>

// struct node {
// 	char c;
// 	node *next = nullptr, *prev = nullptr;
// };
struct node {
	char c;
	node *next = nullptr;
};

class linkedlist {
public:
	linkedlist() {}
	void set(std::string src) {
		if(head != nullptr) {
			erase_all();
		}
		node *n = new node;
		head = n;
		for (unsigned int i = 0; i < src.size()-1; i++) {
			n->c = src[i];
			n->next = new node;
			// n->next->prev = n;
			n = n->next;
		}
		n->c = src[src.size()-1];
		n->next = head;
		// head->prev = n;
		size = src.size();
	}
	void erase_all() {
		node *n = head;
		do {
			delete n;
			n = n->next;
		} while (n->next != nullptr);
		head = nullptr;
	}
	void find_str(std::string target) {
		std::vector<node *> indices_prev;
		node *prev = nullptr;
		node *n = head;
		unsigned int findex = 0;
		while(true) {
			if(n->c == target[findex]) {
				// std::cout<<"same!!\n";
				if(findex == 0) indices_prev.push_back(prev);
				findex++;
				if(target.size() == findex) {
					if(size == target.size()) {
						set("FRULA");
						break;
					}
					findex = 0;
					if(indices_prev.back() == nullptr) {
						// n->next->prev = indices.back()->prev;
						// indices.back()->prev->next = n->next;
						indices_prev.pop_back();
						size -= target.size();
						head = n->next;
						prev = nullptr;
						n = head;
						continue;
					} else {
						print();
						// n->next->prev = indices.back()->prev;
						indices_prev.back()->next = n->next;
						indices_prev.pop_back();
						size -= target.size();
						print();
						if (!indices_prev.empty()) {
							if(indices_prev.back() == nullptr) n = head;
							else n = indices_prev.back()->next;
							findex = 0;
							continue;
						}
					}
				}
			} else if(findex != 0) {
				findex = 0;
				continue;
			}
			if (n->next == head) break;
			prev = n;
			n = n->next;
		}
	}
	void print() {
		node *n = head;
		do {
			std::cout<<n->c;
			n = n->next;
		} while (n != head);
		std::cout<<"\n";
	}

private:
	node *head = nullptr;
	unsigned int size = 0;
};

int main(int argc, char const *argv[])
{
	std::string src;
	std::string bomb;

	std::cin>>src>>bomb;

	linkedlist ll;
	ll.set(src);
	ll.find_str(bomb);
	ll.print();


	return 0;
}
