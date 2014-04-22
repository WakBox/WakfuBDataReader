package com.ankamagames.wakfu.client.binaryStorage;

public class AlmanachDateBinaryData implements dEZ {
    protected int az;
    protected java.sql.Timestamp mCB;
    protected int mCC;
    
    public AlmanachDateBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public java.sql.Timestamp dxj()
    {
        return this.mCB;
    }
    
    public int dxk()
    {
        return this.mCC;
    }
    
    public void reset()
    {
        this.az = 0;
        this.mCB = null;
        this.mCC = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.mCB = new java.sql.Timestamp(a.getLong());
        this.mCC = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eFk.getId();
    }
}