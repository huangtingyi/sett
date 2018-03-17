import java.io.*;
import jxl.*;
import jxl.write.*;

public class readxls{

public static void main(String[] args)
{

String CellValue="",XlsName="";
String filename=args[1],xlsfilename=args[0];
int SheetNum=1,iTemp=0,rsRows=0,rsColumns=0;
	
jxl.Workbook rwb = null;

File file = new File(filename);


try{
	Writer fw = new FileWriter(file);
	BufferedWriter bw = new BufferedWriter(fw);

	//直接从本地文件创建Workbook
	File infile = new File(xlsfilename);
	InputStream is = new FileInputStream(infile);
	rwb = Workbook.getWorkbook(is);
	
	//获得工作薄（Workbook）中工作表（Sheet）的个数
	SheetNum = rwb.getNumberOfSheets();
	
	Sheet[] sheet = rwb.getSheets();
	Sheet rs = sheet[0];
	
	for (int i = 0; i<SheetNum; i++){
		
		bw.write("sheet="+i+"\n");
		rs = rwb.getSheet(i);
		rsRows = rs.getRows();
		rsColumns = rs.getColumns();

		for (int j = 0; j<rsRows; j++){
			for (int k = 0; k<rsColumns; k++){
				CellValue = rs.getCell(k, j).getContents();
				bw.write(CellValue+"\t");
			}
			bw.write("\r\n");
		}
//		bw.write("line="+rsRows+" column="+rsColumns+"\r\n");
		if(i>=23) break;//暂时不导入短信报表
	}
	bw.close();
	fw.close();
}
catch(Exception e){
	e.printStackTrace();
}
finally{
	rwb.close();
}
}

}