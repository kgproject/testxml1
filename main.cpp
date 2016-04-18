#include <QtCore/QCoreApplication>  
#include <QFile>  
#include <QTextCodec>  
#include <QDomDocument>  

int main(int argc, char *argv[])  
{  
    QTextCodec *codec = QTextCodec::codecForName("utf-8");  
    QTextCodec::setCodecForLocale(codec);  
    QTextCodec::setCodecForCStrings(codec);  
    QTextCodec::setCodecForTr(codec);  

    QCoreApplication a(argc, argv);  
    QDomDocument doc;  
    QFile xmlfile("index.xml"); 



    if (!xmlfile.open(QIODevice::ReadOnly))  
    {  
        return false;  
    }  
    if (!doc.setContent(&xmlfile))  
    {  
        xmlfile.close();  
        return false;  
    }  
    QDomElement root = doc.documentElement();  
    QDomNode node=root.firstChild().firstChild().nextSibling();  
    qDebug(node.toElement().text().toAscii());  
    qDebug(node.nodeName().toAscii());  

    return a.exec();  
}
  
