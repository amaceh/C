/*
Class BookPublisher yang mengimplementasikan Interface dari IndustryComponents
*/

class BookPublisher implements BookIndustryComponent{
	//attribut
	private String PublisherCode,PublisherName,PublisherAddress, PublisherDescription;

	BookPublisher(){

	}
	//set method yang diiplmentasikan dari interface
	public void setCode(String code){
		this.PublisherCode = code;
	}
	public void setName(String name){
		this.PublisherName = name;
	}

	public void setDescription(String desc){
		this.PublisherDescription = desc;
	}
	//set method lain
	public void setAddress(String addr){
		this.PublisherAddress = addr;
	}

	//get method yang diimplementakan dari interface
	public String getCode(){
		return this.PublisherCode;
	}
	public String getName(){
		return this.PublisherName;
	}
	public String getDescription(){
		return this.PublisherDescription;
	}
	//get method lain
	public String getAddress(){
		return this.PublisherAddress;
	}
}