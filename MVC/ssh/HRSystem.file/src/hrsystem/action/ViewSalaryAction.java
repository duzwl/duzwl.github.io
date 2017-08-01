package hrsystem.action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.opensymphony.xwork2.*;
import org.apache.struts2.interceptor.*;

import hrsystem.service.EmpManager;
import hrsystem.exception.HrException;
import hrsystem.action.base.EmpBaseAction;

import hrsystem.vo.*;

import java.util.*;


public class ViewSalaryAction extends EmpBaseAction
{
	// 封装所有发薪信息的List
	private List salarys;
	
	// salarys属性的setter和getter方法
	public void setSalarys(List salarys)
	{
		this.salarys = salarys;
	}
	public List getSalarys()
	{
		return this.salarys;
	}
	
	// 处理用户请求的方法
	public String execute()
		throws Exception
	{
		// 创建ActionContext实例
		ActionContext ctx = ActionContext.getContext();
		// 获取HttpSession中的user属性
		String user = (String)ctx.getSession()
			.get(WebConstant.USER);
		List<PaymentBean> salarys =  mgr.empSalary(user);
		setSalarys(salarys);
		return SUCCESS;
	}
}
