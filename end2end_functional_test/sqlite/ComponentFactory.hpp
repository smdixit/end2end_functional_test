using namespace std;

/*
Currently, only one In/Out table is mapped to a component.
If more than one table is to be mapped, may be its handle or name must
be passed to this.
*/
class ComponentFactory{
public:
	PopulateItems * CreateComponent(string ComponentName, PopulateItems *pPopulateItems){
		cout << __FUNCTION__ << __LINE__ << endl;
        if (ComponentName.compare("CommonInputs") == 0) {
			return new Pop_BlinkerManager; //Populate from Table
	     }
	}
	DumpFromProgram * CreateComponent(string ComponentName, DumpFromProgram *pDumpFromProgram) {
		if (ComponentName.compare("BlinkerManager") == 0) {
			cout << __FUNCTION__ << __LINE__ << endl;
			return new Depop_BlinkManager; //Populate from Table
		}
	}
};
