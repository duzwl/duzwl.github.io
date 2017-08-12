package hrsystem.action;

import java.util.List;

import hrsystem.action.base.EmpBaseAction;

public class AppChangeAction
	extends EmpBaseAction
{
	// 封装所有异动的列表
	private List types;
	
	// types属性的setter和getter方法
	public void setTypes(List types)
	{
		this.types = types;
	}
	public List getTypes()
	{
		return this.types;
	}
	
	// 处理用户请求
	public String execute()
		throws Exception
	{
		setTypes(mgr.getAllType());
		return SUCCESS;
	}
}
