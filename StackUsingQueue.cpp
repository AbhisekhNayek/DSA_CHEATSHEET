class Stack {
	// Define the data members.
    queue < int > q1,q2;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if (q1.empty()){return 1;}
        else return 0;
    }
    //USING SINGLE QUEUE--->
    void push(int element) {
        // Implement the push() function.
        q1.push(element);
        for (int i = 0; i<q1.size()-1 ; i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    //USING TWO QUEUES------->
    // void push(int element) {
    //     // Implement the push() function.
    //     q2.push(element);
    //     while(!q1.empty()){
    //         q2.push(q1.front());
    //         q1.pop();
    //     }swap(q1,q2);
    // }

    int pop() {
        // Implement the pop() function.
        if (q1.empty()){return -1;}
        else
        {
            int e = q1.front();
            q1.pop();
            return e;
        }
    }

    int top() {
        // Implement the top() function.
        if (q1.empty()){return -1;}
        else return q1.front();
    }
};
