package com.ankamagames.wakfu.client.binaryStorage;

public class BagsBinaryData implements dEZ {
    protected int az;
    protected short czI;
    protected int jcW;
    protected int[] jcX;
    
    public BagsBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short aeT()
    {
        int i = this.czI;
        return (short)i;
    }
    
    public int cMe()
    {
        return this.jcW;
    }
    
    public int[] cMf()
    {
        return this.jcX;
    }
    
    public void reset()
    {
        this.az = 0;
        this.czI = (short)0;
        this.jcW = 0;
        this.jcX = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.czI = (short)i;
        this.jcW = a.getInt();
        this.jcX = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eFG.getId();
    }
}