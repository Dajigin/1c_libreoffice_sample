#include <com/sun/star/lang/XMultiComponentFactory.hpp> 
#include <cppuhelper/bootstrap.hxx>
#include <rtl/ustring.hxx>
#include <iostream>
#include <sal/main.h>

#include <iostream>
#include <sal/main.h>
#include <cppuhelper/bootstrap.hxx>

#include <osl/file.hxx>
#include <osl/process.h>
#include <rtl/process.h>

#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/bridge/XUnoUrlResolver.hpp>
#include <com/sun/star/frame/Desktop.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>
#include <com/sun/star/frame/XModel.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <com/sun/star/registry/XSimpleRegistry.hpp>

#include <com/sun/star/text/XTextDocument.hpp>

using namespace com::sun::star::uno;
using namespace com::sun::star::lang;
using namespace com::sun::star::beans;
using namespace com::sun::star::bridge;
using namespace com::sun::star::frame;
using namespace com::sun::star::registry;
using namespace css::text;

using namespace rtl;

extern int hello() {
    try {
      Reference<css::uno::XComponentContext> xContext(
          cppu::bootstrap());
      std::cout << "Connected to a running office ..." << std::endl;
      Reference<css::lang::XMultiComponentFactory> xMCF =
          xContext->getServiceManager();
      std::string availableCF = xMCF != nullptr ? "available" : "not available";
      std::cout << "remote ServiceManager is " + availableCF << std::endl;

      Reference <css::uno::XInterface> rDesktop = xMCF->createInstanceWithContext(OUString::createFromAscii("com.sun.star.frame.Desktop"), xContext);
      std::string availableDesktop = rDesktop != nullptr ? "available" : "not available";
      std::cout << "Desktop is " + availableDesktop << std::endl;
      
      Reference<XComponentLoader> rComponentLoader(rDesktop,UNO_QUERY);      
      std::string availableCompLoader = rComponentLoader != nullptr ? "available" : "not available";
      std::cout << "Component loader " + availableCompLoader << std::endl;

       Sequence< ::com::sun::star::beans::PropertyValue > loadProps(0);
       Reference< XComponent > rWriter = rComponentLoader->loadComponentFromURL(  
         OUString::createFromAscii("private:factory/swriter"),
         OUString::createFromAscii("_blank"),
         0,
         loadProps);
      std::string availableComponent = rWriter != nullptr ? "available" : "not available";
      std::cout << "Component " + availableCompLoader << std::endl;

      Reference<::com::sun::star::text::XTextDocument> rTextDoc(rWriter, UNO_QUERY);
      std::string availableTextDoc = rTextDoc != nullptr ? "available" : "not available";
      std::cout << "Text document " + availableTextDoc << std::endl;

      Reference<XText> rText=rTextDoc->getText();
      std::string availableText = rText != nullptr ? "available" : "not available";
      std::cout << "Text " + availableText << std::endl;

      rText->setString(OUString::createFromAscii("Hello, LibreOffice!!!"));

    } catch (css::uno::Exception &e) {
      std::cout << e.Message << std::endl;
      return 1;
    }
    return 0;
  
}