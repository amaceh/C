

class BookGenreCategory{
	private String BookGenreCode,BookGenreName,BookGenreDescription;

	BookGenreCategory(){

	}

	public void setCode(String code){
		this.BookGenreCode = code;
	}
	public void setName(String name){
		this.BookGenreName = name;
	}
	public void setDescription(String desc){
		this.BookGenreDescription = desc;
	}

	public String getCode(){
		return this.BookGenreCode;
	}
	public String getName(){
		return this.BookGenreName;
	}
	public String getDescription(){
		return this.BookGenreDescription;
	}
}