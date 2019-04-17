#include "TRestTask.h"
#include "TRestG4Metadata.h"
#include "TRestG4Event.h"
#include <fstream>
#include <sstream>

//REST_ReadHitsEvents
Int_t REST_ExportHitsEvents( TString fName )
{
    TRestRun *run = new TRestRun();

    string fname = fName.Data();
    if( !fileExists( fname ) ) { cout << "WARNING. Input file does not exist" << endl; exit(1); }
    else run->OpenInputFile( fName );

    run->OpenInputFile( fName );

    run->PrintInfo();
    int total_Event = run->GetEntries();
    cout<<"total_Event is "<<total_Event<<endl;
    /////////////////////////////

    /////////////////////////////
    // Reading events

    cout<<"hello REST_ExportHitsEvents"<<endl;
    TRestHitsEvent *ev = new TRestHitsEvent();

    run->SetInputEvent( ev );
   // double x,y,z ,total_energy; 

    ofstream outfile_dep_x_y_z ;
    string str1="_event_dep_x_y_z.txt";
    //string str2="___kf_gain.txt";
    //string str3="___smooth_gain.txt";
    double  x, y, z, Edep;
    for(int i=0; i<total_Event;i++)
    {
            run->GetEntry ( i );
            int Nhits = ev -> GetNumberOfHits();
            outfile_dep_x_y_z.open( ev -> GetID()+str1);
            outfile_dep_x_y_z << Nhits << endl ; 
            for (int h = 0; h < Nhits; h++)
            {
              
                x    = ev->GetX (h) ;
                y    = ev->GetY (h) ;
                z    = ev->GetZ (h) ;
                Edep = ev->GetEnergy (h) ;

            outfile_dep_x_y_z << Edep << " " \
                        << x << " " << y << " " << z <<endl;
            
            }
            outfile_dep_x_y_z.close();
    }

    delete ev;


    /////////////////////////////

    delete run;

    return 0;
}
