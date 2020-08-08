class Context {
	private TCPState ts;
	
	public Context() { 
		this.ts = new TCPClosed();
	}
	public void set(TCPState ts) {
		this.ts = ts;
	}
	public void open() {
		ts.open(this);
	}
	public void close() {
		ts.close(this);
	}
	public void knowledge() {
		ts.knowledge(this);
	}
}

interface TCPState {
	public void open(Context tc);
	public void close(Context tc);
	public void knowledge(Context tc);
}

class TCPClosed implements TCPState {
	public void open(Context tc) {
		tc.set(new TCPListen()); //�}�l�s�u
	}
	public void close(Context tc) {} //"�w����!"
	public void knowledge(Context tc) {}//"�w����!�Х��}�ҳs�u"
}

class TCPListen implements TCPState {
	public void open(Context tc) {}//"�s�u��..."
	public void close(Context tc) {
		tc.set(new TCPClosed()); //"���_�s�u"
	}
	public void knowledge(Context tc) {
		tc.set(new TCPing()); //"�s�u���\!"
	}
}

class TCPing implements TCPState {
	public void open(Context tc) {}//"�w�s�u!"
	public void close(Context tc) {
		tc.set(new TCPClosed()); //"�_�}�s�u"
	}
	public void knowledge(Context tc) {}//"�w�b�s�u���A!!"
}

public class StateDemo {
	public static void main(String[] args) {
		Context tc = new Context();
	
		tc.open();
		tc.knowledge();
		tc.close();
	}
}
 