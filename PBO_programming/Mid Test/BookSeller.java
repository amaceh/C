/*
Class bookseller
BookSeller
- SellerCode
- SellerName
- SellerAddress
*/

class BookSeller{
	//attribute
	private String SellerCode,SellerName,SellerAddress;
	//blank contructor
	BookSeller(){

	}

	//Set Moethods
	public void setCode(String code){
		this.SellerCode = code;
	}
	public void setName(String name){
		this.SellerName = name;
	}
	public void setAddress(String addr){
		this.SellerAddress = addr;
	}

	//get methods
	public String getCode(){
		return this.SellerCode;
	}
	public String getName(){
		return this.SellerName;
	}
	public String getAddress(){
		return this.SellerAddress;
	}
}