package hrsystem.exception;

@SuppressWarnings("serial")
public class HrException extends Exception
{
	public HrException() {}
	public HrException(String msg)
	{
		super(msg);
	}
}
