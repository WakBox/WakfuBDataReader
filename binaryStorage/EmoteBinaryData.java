package com.ankamagames.wakfu.client.binaryStorage;

public class EmoteBinaryData implements dEZ {
    protected int az;
    protected short eqi;
    protected String exb;
    protected boolean exc;
    protected boolean exd;
    protected boolean exe;
    protected boolean exf;
    protected String[] exg;
    
    public EmoteBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short getType()
    {
        int i = this.eqi;
        return (short)i;
    }
    
    public String aYJ()
    {
        return this.exb;
    }
    
    public boolean aYK()
    {
        return this.exc;
    }
    
    public boolean aYL()
    {
        return this.exd;
    }
    
    public boolean aYM()
    {
        return this.exe;
    }
    
    public boolean aYN()
    {
        return this.exf;
    }
    
    public String[] aYO()
    {
        return this.exg;
    }
    
    public void reset()
    {
        this.az = 0;
        this.eqi = (short)0;
        this.exb = null;
        this.exc = false;
        this.exd = false;
        this.exe = false;
        this.exf = false;
        this.exg = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.eqi = (short)i;
        this.exb = a.clg().intern();
        this.exc = a.readBoolean();
        this.exd = a.readBoolean();
        this.exe = a.readBoolean();
        this.exf = a.readBoolean();
        this.exg = a.cll();
    }
    
    final public int gZ()
    {
        return aPw.eES.getId();
    }
}