import java.util.*;

class pair {
    private int first;
    private int second;

    public pair(int x, int y) {
        first = x;
        second = y;
    }

    public int getFirst() {return this.first;}

    public int getSecond() {return this.second;}
}

public class week2_MinStack {
    private ArrayList<pair> vData = new ArrayList<pair>();
    private int minValue;

    /** initialize your data structure here. */
    public week2_MinStack() {
        this.minValue = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        if (this.vData.size() == 0) {
            this.minValue = x;
            pair p = new pair(x, this.minValue);
            this.vData.add(p);
        }
        else {
            if (x < this.minValue) {
                this.minValue = x;
            }
            pair p = new pair(x, this.minValue);
            this.vData.add(p);
        }
    }
    
    public void pop() {
        this.vData.remove(this.vData.size() - 1);
        if (this.vData.size() != 0) {
            this.minValue = this.vData.get(this.vData.size() - 1).getSecond();
        }
        else this.minValue = Integer.MAX_VALUE;
    }
    
    public int top() {
        return this.vData.get(this.vData.size() - 1).getFirst();
    }
    
    public int getMin() {
        return this.vData.get(this.vData.size() - 1).getSecond();
    }
}