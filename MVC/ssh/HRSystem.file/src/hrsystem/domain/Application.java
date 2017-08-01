package hrsystem.domain;

import java.io.Serializable;

public class Application
	implements Serializable
{
	private static final long serialVersionUID = 48L;
	private Integer id;
	private String reason;
	private boolean result;
	private Attend attend;
	// 希望将指定出勤改为的type类型
	private AttendType type;
	private CheckBack check;
	
	public Application() {}

	public Application(Integer id, String reason, 
		boolean result, Attend attend, 
		AttendType type, CheckBack check)
	{
		this.id = id;
		this.reason = reason;
		this.result = result;
		this.attend = attend;
		this.type = type;
		this.check = check;
	}
	
	public void setId(Integer id)
	{
		this.id = id;
	}
	public Integer getId()
	{
		return this.id;
	}
	
	public void setReason(String reason)
	{
		this.reason = reason;
	}
	public String getReason()
	{
		return this.reason;
	}
	
	public void setResult(boolean result)
	{
		this.result = result;
	}
	public boolean getResult()
	{
		return this.result;
	}
	
	public void setAttend(Attend attend)
	{
		this.attend = attend;
	}
	public Attend getAttend()
	{
		return this.attend;
	}
	
	public void setType(AttendType type)
	{
		this.type = type;
	}
	public AttendType getType()
	{
		return this.type;
	}
	
	public void setCheck(CheckBack check)
	{
		this.check = check;
	}
	public CheckBack getCheck()
	{
		return this.check;
	}
	
}
