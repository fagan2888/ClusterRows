#ifndef COM_GITHUB_DENNISFRANCIS_CLUSTERROWS_HXX
#define COM_GITHUB_DENNISFRANCIS_CLUSTERROWS_HXX

#include <com/sun/star/task/XJob.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/IllegalArgumentException.hpp>
#include <cppuhelper/implbase2.hxx>

#define IMPLEMENTATION_NAME "com.github.dennisfrancis.ClusterRowsImpl"

namespace com
{
    namespace sun
    {
        namespace star
        {
	    namespace frame
	    {
		class XFrame;
	    }
            namespace uno
            {
                class XComponentContext;
            }
	    namespace beans
	    {
		struct NamedValue;
	    }
        }
    }
}

class ClusterRowsImpl : public cppu::WeakImplHelper2
<
    com::sun::star::task::XJob,
    com::sun::star::lang::XServiceInfo
>
{
    
private:
    ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext > mxContext;

public:

    ClusterRowsImpl( const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext > &rxContext )
        : mxContext( rxContext )
    {
	printf("DEBUG>>> Created ClusterRowsImpl object : %p\n", this); fflush(stdout);
    }

    // XAsyncJob methods
    virtual ::com::sun::star::uno::Any SAL_CALL execute(
	const ::com::sun::star::uno::Sequence< ::com::sun::star::beans::NamedValue >& rArgs )
	throw(::com::sun::star::lang::IllegalArgumentException,
	      ::com::sun::star::uno::RuntimeException) override;

    // XServiceInfo methods
    virtual ::rtl::OUString SAL_CALL getImplementationName()
        throw (::com::sun::star::uno::RuntimeException);
    virtual sal_Bool SAL_CALL supportsService( const ::rtl::OUString& aServiceName )
        throw (::com::sun::star::uno::RuntimeException);
    virtual ::com::sun::star::uno::Sequence< ::rtl::OUString > SAL_CALL getSupportedServiceNames()
        throw (::com::sun::star::uno::RuntimeException);

    // A struct to store some job related info when execute() is called
    struct ClusterRowsImplInfo
    {
	::rtl::OUString aEnvType;
	::rtl::OUString aEventName;
	::rtl::OUString aAlias;
	::com::sun::star::uno::Reference< ::com::sun::star::frame::XFrame > xFrame;
    };

private:

    ::rtl::OUString validateGetInfo( const ::com::sun::star::uno::Sequence< ::com::sun::star::beans::NamedValue >& rArgs,
				     ClusterRowsImplInfo& rJobInfo );
    
    void clusterRows( const ClusterRowsImplInfo& rJobInfo, const sal_Int32 nUserNumClusters );
};

::rtl::OUString ClusterRowsImpl_getImplementationName()
    throw ( ::com::sun::star::uno::RuntimeException );

sal_Bool SAL_CALL ClusterRowsImpl_supportsService( const ::rtl::OUString& ServiceName )
    throw ( ::com::sun::star::uno::RuntimeException );

::com::sun::star::uno::Sequence< ::rtl::OUString > SAL_CALL ClusterRowsImpl_getSupportedServiceNames()
    throw ( ::com::sun::star::uno::RuntimeException );

::com::sun::star::uno::Reference< ::com::sun::star::uno::XInterface >
SAL_CALL ClusterRowsImpl_createInstance( const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext > & rContext)
    throw ( ::com::sun::star::uno::Exception );

#endif
