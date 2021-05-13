
//     WILL WORK FOR SORT FUNCTION
bool compare(MinHeapNode* l, MinHeapNode* r){
	return (l->freq > r->freq);
}


//Classes which act as functions by overloading the () operator
// For comparison of two heap nodes (needed in min heap)/maps/sets
class compare{
public:
	// Overloading the function call operaror() as priorit_queue will always use this operator for comparison
	bool operator()(MinHeapNode* l, MinHeapNode* r){
		return (l->freq > r->freq);
	}
};



 priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
