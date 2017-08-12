package hrsystem.action;

import java.util.*;
import java.text.SimpleDateFormat;

import com.opensymphony.xwork2.ActionContext;

import hrsystem.action.base.EmpBaseAction;

public class PunchAction
	extends EmpBaseAction
{
	// ��װ���������punchIsValid����
	private int punchIsValid;
	
	//punchIsValid���Ե�setter��getter����
	public void setPunchIsValid(int punchIsValid)
	{
		this.punchIsValid = punchIsValid;
	}
	public int getPunchIsValid()
	{
		return this.punchIsValid;
	}
	
	public String execute()
		throws Exception
	{
		// ����ActionContextʵ��
		ActionContext ctx = ActionContext.getContext();
		// ��ȡHttpSession�е�user����
		String user = (String)ctx.getSession().get(WebConstant.USER);
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		// ��ʽ����ǰʱ��
		String dutyDay = sdf.format(new Date());
		// ����ҵ���߼����������û�����
		int result = mgr.validPunch(user, dutyDay);
		setPunchIsValid(result);
		return SUCCESS;
	}
}