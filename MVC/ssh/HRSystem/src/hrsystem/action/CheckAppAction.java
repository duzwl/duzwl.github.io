package hrsystem.action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.opensymphony.xwork2.*;
import org.apache.struts2.interceptor.*;

import hrsystem.service.EmpManager;
import hrsystem.exception.HrException;
import hrsystem.action.base.MgrBaseAction;

public class CheckAppAction extends MgrBaseAction
{
	// ��Ҫ������������ID
	private int appid;
	// ��װ�������
	private String result;
	// ��װ������ʾ
	private String tip;
	
	// appid���Ե�setter��getter����
	public void setAppid(int appid)
	{
		this.appid = appid;
	}
	public int getAppid()
	{
		return this.appid;
	}

	// result���Ե�setter��getter����
	public void setResult(String result)
	{
		this.result = result;
	}
	public String getResult()
	{
		return this.result;
	}

	// tip���Ե�setter��getter����
	public void setTip(String tip)
	{
		this.tip = tip;
	}
	public String getTip()
	{
		return this.tip;
	}
	
	public String execute()
		throws Exception
	{
		// ����ActionContextʵ��
		ActionContext ctx = ActionContext.getContext();
		// ��ȡHttpSession�е�user����
		String mgrName = (String)ctx.getSession()
			.get(WebConstant.USER);
		// ͨ������
		if (result.equals("pass"))
		{
			mgr.check(appid, mgrName, true);
		}
		// �ܾ�����
		else if (result.equals("deny"))
		{
			mgr.check(appid, mgrName, false);		  
		}
		else
		{
			throw new Exception("������ʧ");
		}
		setTip("����Ա������ɹ�");
		return SUCCESS;
	}
}