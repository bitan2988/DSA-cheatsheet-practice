/*HUFFMAN ENCODING  (https://www.youtube.com/watch?v=co4_ahEDCho)
----------------

OPTIMAL MERGE PATTERN IS A GREEDY APPROACH i.e always selecting the two minimumm one

Follows Optimal Merge Pattern (rope problem using min-heap). it says we can allot less bits to a char which appears more and higbher bits to chars which appear less thus reducing the time.

	Arrange all the chars in their increasing order of their appearance.
	Merge two smallest one(depending on their frequency) and make one single node & again insert it into the heap
	Repeat the process until we are left with one single node

	Mark the left side edges as zeroes and the right hand side edges as one.

	Now for eacch alphabet follow the path from root onwards 

	SIZE OF MESSAGE = sumission(Fi*Di) ; Fi = frequency of the char    Di = distance of that char from the root node */


#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
class MinHeapNode{
public:
	char data;
	unsigned freq;
	MinHeapNode* left;
	MinHeapNode* right;

	MinHeapNode(char val, unsigned count){
		data = val;
		freq = count;
		left = right = NULL;
	}
};


// For comparison of two heap nodes (needed in min heap)
/*       WILL WORK FOR SORT FUNCTION
bool compare(MinHeapNode* l, MinHeapNode* r){
	return (l->freq > r->freq);
}*/
class compare{
public:
	// Overloading the function call operaror() as priorit_queue will always use this operator for comparison
	bool operator()(MinHeapNode* l, MinHeapNode* r){
		return (l->freq > r->freq);
	}
};

// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes frequencies. 
        // Make the two extracted node as left and right children of this new node.
        // Add this node to the min heap '$' is a special value for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}

int main()
{

    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}


