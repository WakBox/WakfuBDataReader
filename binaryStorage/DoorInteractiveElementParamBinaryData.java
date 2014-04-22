package com.ankamagames.wakfu.client.binaryStorage;

public class DoorInteractiveElementParamBinaryData implements dEZ {
    protected int az;
    protected int UA;
    protected boolean cMe;
    protected int cMf;
    protected int cMg;
    protected String Uz;
    
    public DoorInteractiveElementParamBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int gX()
    {
        return this.UA;
    }
    
    public boolean ald()
    {
        return this.cMe;
    }
    
    public int ale()
    {
        return this.cMf;
    }
    
    public int alf()
    {
        return this.cMg;
    }
    
    public String gW()
    {
        return this.Uz;
    }
    
    public void reset()
    {
        this.az = 0;
        this.UA = 0;
        this.cMe = false;
        this.cMf = 0;
        this.cMg = 0;
        this.Uz = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.UA = a.getInt();
        this.cMe = a.readBoolean();
        this.cMf = a.getInt();
        this.cMg = a.getInt();
        this.Uz = a.clg().intern();
    }
    
    final public int gZ()
    {
        return aPw.eFD.getId();
    }
}