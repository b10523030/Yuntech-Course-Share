package Memento_Command;

public class originator {
	//�|��create memento ����k
	//�s��memento �������Ҧ����
	public String text;
	
	public void setText(String text) {
		this.text = text;
	}
	
	public memento storeInMemento() {
		System.out.println("store in memento ~");
		return new memento(text);
	}
	
	public String restoreMemento(memento m) {
		text = m.getText();
		return text;
	}
}
