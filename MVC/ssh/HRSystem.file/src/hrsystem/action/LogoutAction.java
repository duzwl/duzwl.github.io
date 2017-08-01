package hrsystem.action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.opensymphony.xwork2.*;
import org.apache.struts2.interceptor.*;

public class LogoutAction extends ActionSupport
	implements ServletRequestAware
{
	// 定义一个HttpServletRequest对象
	private HttpServletRequest request;
	
	// 实现ServletRequestAware接口必须重写的方法
	public void setServletRequest(HttpServletRequest request)
	{
		this.request = request;
	}
	
	public String execute()
		throws Exception
	{
		// 获取HttpSession
		HttpSession session = request.getSession();
		// 使Session失效
		session.invalidate();
		return SUCCESS;
	}
}
