package com.ankamagames.wakfu.client.binaryStorage;

public class CensoredEntryBinaryData implements dEZ {
    protected int az;
    protected boolean dZO;
    protected int fOo;
    protected int fOp;
    protected String hI;
    
    public CensoredEntryBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public boolean aLL()
    {
        return this.dZO;
    }
    
    public int bAq()
    {
        return this.fOo;
    }
    
    public int bAr()
    {
        return this.fOp;
    }
    
    public String getText()
    {
        return this.hI;
    }
    
    public void reset()
    {
        this.az = 0;
        this.dZO = false;
        this.fOo = 0;
        this.fOp = 0;
        this.hI = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.dZO = a.readBoolean();
        this.fOo = a.getInt();
        this.fOp = a.getInt();
        this.hI = a.clg().intern();
    }
    
    final public int gZ()
    {
        return aPw.eDC.getId();
    }
}