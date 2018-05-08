//i inherit this class because this class look 
//like the combination of the sparepart
class FullBody: public SparePart{
private:
	int size;
public:
	FullBody(){};
	//set and get
	void setSize(int size){
		this->size=size;
	}
	int getSize(){
		return size;
	}
	//declare friend void
	friend void PrintRobot(SparePart s, FullBody f);
	~FullBody(){};
		
};