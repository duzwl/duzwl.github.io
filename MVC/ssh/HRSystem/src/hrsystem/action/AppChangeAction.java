package hrsystem.action;

import java.util.List;

import hrsystem.action.base.EmpBaseAction;

public class AppChangeAction
	extends EmpBaseAction
{
	// ��װ�����춯���б�
	private List types;
	
	// types���Ե�setter��getter����
	public void setTypes(List types)
	{
		this.types = types;
	}
	public List getTypes()
	{
		return this.types;
	}
	
	// �����û�����
	public String execute()
		throws Exception
	{
		setTypes(mgr.getAllType());
		return SUCCESS;
	}
}
