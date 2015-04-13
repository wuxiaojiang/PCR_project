package com.example.test_client;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

import android.support.v7.app.ActionBarActivity;
import android.util.Log;
import android.view.View;
import android.view.WindowInsets;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.os.Bundle;


public class MainActivity extends ActionBarActivity {
	private Button run,stop,test,pause,save;
	private TextView con;
	private EditText host;
	private String ho,msg;
	private int port=1080;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        run = (Button)findViewById(R.id.b_run);
        stop = (Button)findViewById(R.id.b_stop);
        test = (Button)findViewById(R.id.b_test);
        save = (Button)findViewById(R.id.b_save);
        pause = (Button)findViewById(R.id.b_pause);
        con = (TextView)findViewById(R.id.condition);
        host = (EditText)findViewById(R.id.editText1);
        run.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				msg = "run";
				ho = host.getText().toString();
				new ServerThead().start();			
			}
		});
        stop.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				msg = "stop";
				ho = host.getText().toString();
				new ServerThead().start();
			}
		});
        test.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				msg = "test";
				ho = host.getText().toString();
				new ServerThead().start();
			}
		});
        pause.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				msg = "pause";
				ho = host.getText().toString();
				new ServerThead().start();	
			}
		});
        
        
    }
    class ServerThead extends Thread{
    	public void run(){
    		try{
    			DatagramSocket sock = new DatagramSocket(port);
    			InetAddress serverAddress = InetAddress.getByName(ho);
    			byte data[] = msg.getBytes();
    			DatagramPacket packet = new DatagramPacket(data, data.length, serverAddress, port);
    			sock.send(packet);
    			Log.d("server","send...");
    			sock.close();}
    			
    			
    		catch(Exception e){
    			e.printStackTrace();
    		}
    		}
    		
    	}

}
