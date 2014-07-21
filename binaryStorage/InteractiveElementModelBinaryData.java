package com.ankamagames.wakfu.client.binaryStorage;

public class InteractiveElementModelBinaryData implements dEZ {
    protected int viewId;
    protected short type;
    protected int gfx;
    protected int color;
    protected byte height;
    protected int ddd;
    protected int edU;
    
    public InteractiveElementModelBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.viewId;
    }
    
    public short getType()
    {
        int i = this.type;
        return (short)i;
    }
    
    public int ant()
    {
        return this.gfx;
    }
    
    public int aFz()
    {
        return this.color;
    }
    
    public byte ci()
    {
        int i = this.height;
        return (byte)i;
    }
    
    public int arj()
    {
        return this.ddd;
    }
    
    public int aVd()
    {
        return this.edU;
    }
    
    public void reset()
    {
        this.viewId = 0;
        this.type = (short)0;
        this.gfx = 0;
        this.color = 0;
        this.height = (byte)0;
        this.ddd = 0;
        this.edU = 0;
    }
    
    public void a(ceb a)
    {
        this.viewId = a.getInt();
        int i = a.getShort();
        this.type = (short)i;
        this.gfx = a.getInt();
        this.color = a.getInt();
        int i0 = a.get();
        this.height = (byte)i0;
        this.ddd = a.getInt();
        this.edU = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eDX.getId();
    }
}